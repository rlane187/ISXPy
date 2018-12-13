#include "ISXPyPCH.h"
#include "ISXPy.h"
#include "LGUIPyFrame.h"

LGUIFactory<LGUIPyFrame> PyFrameFactory("pyframe");

LGUIPyFrame::LGUIPyFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name):LGUIFrame(p_Factory,p_pParent,p_Name)
{
	pText=0;
	Count=0;
}
LGUIPyFrame::~LGUIPyFrame(void)
{
}
bool LGUIPyFrame::IsTypeOf(char *TestFactory)
{
	return (!_stricmp(TestFactory,"pyframe")) || LGUIFrame::IsTypeOf(TestFactory);
}
bool LGUIPyFrame::FromXML(class XMLNode *pXML, class XMLNode *pTemplate)
{
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate(XMLHelper::GetStringAttribute(pXML,"Template"));
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate("pyframe");
	if (!LGUIFrame::FromXML(pXML,pTemplate))
		return false;

	// custom xml properties
	return true;
}

void LGUIPyFrame::OnCreate()
{
	// All children of this element are guaranteed to have been created now.
	pText = (LGUIText*)FindUsableChild("Output","text");
}

void LGUIPyFrame::Render()
{
	Count++;
	if (pText)
	{
		char Temp[256];
		sprintf_s(Temp,"This frame has been rendered %d times.",Count);
		pText->SetText(Temp);
	}

	LGUIFrame::Render();
}


