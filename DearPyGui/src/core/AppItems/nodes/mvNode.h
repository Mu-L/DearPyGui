#pragma once
#include "mvAppItem.h"
#include <stdint.h>

namespace Marvel {

	PyObject* add_node(PyObject* self, PyObject* args, PyObject* kwargs);

	MV_REGISTER_WIDGET(mvNode);
	class mvNode : public mvAppItem
	{

		friend class mvNodeEditor;

		MV_APPITEM_TYPE(mvAppItemType::mvNode, "add_node")

		MV_START_COLOR_CONSTANTS
		MV_END_COLOR_CONSTANTS

		MV_START_STYLE_CONSTANTS
		MV_END_STYLE_CONSTANTS

	public:

		static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

	public:

		mvNode(const std::string& name);

		void setNodePos(float x, float y);

		void draw() override;

		int getId() const {return m_id;}

#ifndef MV_CPP
		void setExtraConfigDict(PyObject* dict) override;
		void getExtraConfigDict(PyObject* dict) override;
#endif // !MV_CPP

	private:

	    int m_id = 0;
		bool m_dirty_pos = true;
		int m_xpos = 100;
		int m_ypos = 100;
		bool m_draggable = true;
	};

}