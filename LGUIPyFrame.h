#pragma once

class LGUIPyFrame :
	public LGUIFrame
{
public:
	LGUIPyFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIPyFrame(void);
	bool IsTypeOf(char *TestFactory);
	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	void OnCreate();
	void Render();

	LGUIText *pText;
	unsigned int Count;
};

extern LGUIFactory<LGUIPyFrame> PyFrameFactory;

