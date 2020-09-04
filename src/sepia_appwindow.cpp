/**********************************************************************
 * sepia_appwindow.cpp
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

#include "sepia_appwindow.h"

SepiaAppWindow* SepiaAppWindow::create()
{
	auto refBuilder = Gtk::Builder::create_from_resource("/br/eng/rodolfo/sepia/appwindow.ui");

	SepiaAppWindow* window = nullptr;
	refBuilder->get_widget_derived("app_window", window);
	if (!window)
		throw std::runtime_error("No \"app_window\" object in appwindow.ui");

	return window;
}

void SepiaAppWindow::open_file_view(const Glib::RefPtr<Gio::File>& /*file*/)
{

}

SepiaAppWindow::SepiaAppWindow(BaseObjectType* cobject,
							   const Glib::RefPtr<Gtk::Builder>& refBuilder)
	: Gtk::ApplicationWindow(cobject),
	  m_refBuilder(refBuilder)
{

}

