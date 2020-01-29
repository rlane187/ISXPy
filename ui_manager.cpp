#include "ISXPyPCH.h"
#include "ISXPy.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

unsigned long long frames = 0;
bool show_ui = true;

LRESULT CALLBACK temp_wnd_proc(HWND, UINT, WPARAM, LPARAM);
typedef HRESULT(WINAPI* o_end_scene) (LPDIRECT3DDEVICE9);
typedef HRESULT(WINAPI* o_reset) (LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
typedef HRESULT(WINAPI* o_present) (LPDIRECT3DDEVICE9, const RECT*, const RECT*, HWND, const RGNDATA*);
static o_end_scene end_scene;
static o_reset reset;
static o_present present;
HRESULT WINAPI endscene_detour(LPDIRECT3DDEVICE9);
DETOUR_TRAMPOLINE_EMPTY(HRESULT WINAPI endscene_trampoline(LPDIRECT3DDEVICE9))
HRESULT WINAPI reset_detour(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
DETOUR_TRAMPOLINE_EMPTY(HRESULT WINAPI reset_trampoline(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*))
HRESULT WINAPI present_detour(LPDIRECT3DDEVICE9, const RECT*, const RECT*, HWND, const RGNDATA*);
DETOUR_TRAMPOLINE_EMPTY(HRESULT WINAPI present_trampoline(LPDIRECT3DDEVICE9, const RECT*, const RECT*, HWND, const RGNDATA*))
WNDPROC o_wnd_proc;
WNDPROC original_wnd_proc;
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

void render_main_ui()
{
	ImGui::Text("Hello World");
}

LRESULT __stdcall wnd_proc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(o_wnd_proc, hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK temp_wnd_proc(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	return(DefWindowProc(h_wnd, msg, w_param, l_param));
}

bool initialize_directx_hooks()
{
	HWND  h_wnd_active = GetActiveWindow();
	original_wnd_proc = (WNDPROC)GetWindowLongPtr(h_wnd_active, GWL_WNDPROC);
	o_wnd_proc = (WNDPROC)SetWindowLongPtr(h_wnd_active, GWL_WNDPROC, (LONG_PTR)wnd_proc);
	
	IDirect3DDevice9* pp_returned_device_interface;

	const auto h_dll = GetModuleHandleA("d3d9");
	const auto p_direct3d_create9 = reinterpret_cast<LPDIRECT3D9(__stdcall*)(UINT)>(GetProcAddress(
		h_dll, "Direct3DCreate9"));

	auto p_d3d = p_direct3d_create9(D3D_SDK_VERSION);

	D3DDISPLAYMODE d3ddm;
	HRESULT h_res = p_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = d3ddm.Format;

	WNDCLASSEX wc = { sizeof(WNDCLASSEX),CS_CLASSDC,temp_wnd_proc,0L,0L,GetModuleHandle(NULL),NULL,NULL,NULL,NULL,("1"),NULL };
	RegisterClassEx(&wc);
	auto h_wnd = CreateWindow(("1"), NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);

	h_res = p_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		h_wnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT,
		&d3dpp, &pp_returned_device_interface);

	p_d3d->Release();
	DestroyWindow(h_wnd);

	if (p_d3d == NULL) 
	{
		return false;
	}

	const auto p_interface = reinterpret_cast<unsigned long*>(*reinterpret_cast<unsigned long*>(pp_returned_device_interface));
	end_scene = reinterpret_cast<o_end_scene>(p_interface[42]);
	EzDetour(end_scene, endscene_detour, endscene_trampoline);
	reset = reinterpret_cast<o_reset>(p_interface[16]);
	EzDetour(reset, reset_detour, reset_trampoline);
	present = reinterpret_cast<o_present>(p_interface[17]);
	EzDetour(present, present_detour, present_trampoline);
	return true;	
}

bool shutdown_directx_hooks()
{
	EzUnDetour(end_scene);
	EzUnDetour(reset);
	EzUnDetour(present);
	HWND  h_wnd_active = GetActiveWindow();
	SetWindowLongPtr(h_wnd_active, GWL_WNDPROC, (LONG_PTR)original_wnd_proc);
	return true;
}

HRESULT WINAPI endscene_detour(LPDIRECT3DDEVICE9 p_device)
{
	if (show_ui)
	{
		static bool init = true;

		if (init)
		{
			init = false;			
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.DeltaTime = 1.0f / 60.0f;
			io.Fonts->AddFontDefault();
			ImGui_ImplWin32_Init(GetActiveWindow());
			ImGui_ImplDX9_Init(p_device);
			ImGui::StyleColorsDark();
		}

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		render_main_ui();

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());		
	}
		
	if (frames % 1000 == 0)
		printf("Tick");
	
	frames++;
	
	if (GetAsyncKeyState(VK_DELETE) & 1)
	{
		show_ui = !show_ui;
	}
	
	return endscene_trampoline(p_device);
}

HRESULT WINAPI reset_detour(LPDIRECT3DDEVICE9 p_device, D3DPRESENT_PARAMETERS* p_d3d_present_parameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT h_result = reset_trampoline(p_device, p_d3d_present_parameters);
	ImGui_ImplDX9_CreateDeviceObjects();
	return h_result;
}

HRESULT WINAPI present_detour(LPDIRECT3DDEVICE9 p_device, const RECT* p_source_rect, const RECT* p_dest_rect, HWND h_wnd, const RGNDATA* p_dirty_region)
{
	return present_trampoline(p_device, p_source_rect, p_dest_rect, h_wnd, p_dirty_region);
}
