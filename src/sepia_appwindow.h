/**********************************************************************
 * sepia_appwindow.h
 *
 * Copyright © 2020 Rodolfo Ribeiro Gomes
 *
 * This file is part of Sepia.
 *
 * Sepia is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sepia is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sepia.  If not, see <https://www.gnu.org/licenses/>.
**********************************************************************/

#ifndef SEPIA_APPWINDOW_H
#define SEPIA_APPWINDOW_H

#include <gtkmm.h>

class SepiaAppWindow : public Gtk::ApplicationWindow
{
public:
	static SepiaAppWindow* create();

	void open_file_view(const Glib::RefPtr<Gio::File>& file);

	SepiaAppWindow(BaseObjectType* cobject,
				   const Glib::RefPtr<Gtk::Builder>& refBuilder);

protected:
	Glib::RefPtr<Gtk::Builder> m_refBuilder;
};

#endif // SEPIA_APPWINDOW_H
