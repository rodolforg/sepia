/**********************************************************************
 * sepia_application.h
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

#ifndef SEPIA_APPLICATION_H
#define SEPIA_APPLICATION_H

#include <gtkmm.h>

class SepiaAppWindow;

class SepiaApplication : public Gtk::Application
{
public:
	static Glib::RefPtr<SepiaApplication> create();

protected:
	SepiaApplication();

	void on_activate() override;
	void on_open(const Gio::Application::type_vec_files& files,
				 const Glib::ustring& hint) override;

private:
	SepiaAppWindow* create_appwindow();
	void on_hide_window(Gtk::Window* window);
};

#endif // SEPIA_APPLICATION_H
