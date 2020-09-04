/**********************************************************************
 * sepia_application.cpp
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

#include "sepia_application.h"

#include "sepia_appwindow.h"

#include <exception>
#include <iostream>

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)
#define PACKAGE_NAME TO_STRING(PACKAGE)

SepiaApplication::SepiaApplication()
	: Gtk::Application(PACKAGE_NAME, Gio::APPLICATION_HANDLES_OPEN)
{
}

Glib::RefPtr<SepiaApplication> SepiaApplication::create()
{
	return Glib::RefPtr<SepiaApplication>(new SepiaApplication());
}

SepiaAppWindow* SepiaApplication::create_appwindow()
{
	auto appwindow = SepiaAppWindow::create();

	add_window(*appwindow);

	appwindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this,
																			&SepiaApplication::on_hide_window), appwindow));

	return appwindow;
}

void SepiaApplication::on_activate()
{
	try {
		auto appwindow = create_appwindow();
		appwindow->present();
	} catch (const Glib::Error& ex)	{
		std::cerr << "SepiaApplication::on_activate(): " << ex.what() << std::endl;
	} catch (const std::exception& ex) {
		std::cerr << "SepiaApplication::on_activate(): " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "SepiaApplication::on_activate(): unknown error" << std::endl;
	}
}

void SepiaApplication::on_open(const Gio::Application::type_vec_files& files,
							   const Glib::ustring& /* hint */)
{
	SepiaAppWindow* appwindow = nullptr;
	auto windows = get_windows();
	if (windows.size() > 0)
		appwindow = dynamic_cast<SepiaAppWindow*>(windows[0]);

	try {
		if (!appwindow)
			appwindow = create_appwindow();

		for (const auto& file : files)
			appwindow->open_file_view(file);

		appwindow->present();
	} catch (const Glib::Error& ex)	{
		std::cerr << "SepiaApplication::on_open(): " << ex.what() << std::endl;
	} catch (const std::exception& ex) {
		std::cerr << "SepiaApplication::on_open(): " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "SepiaApplication::on_open(): unknown error" << std::endl;
	}
}

void SepiaApplication::on_hide_window(Gtk::Window* window)
{
	delete window;
}
