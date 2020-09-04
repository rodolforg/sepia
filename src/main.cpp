/**********************************************************************
 * main.cpp
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

#include <gtkmm.h>

#include <libintl.h>

#define _(x) gettext(x)

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)
#define PACKAGE_NAME TO_STRING(PACKAGE)

int main(int argc, char *argv[])
{

	const char * gettext_package = PACKAGE_NAME;
	bindtextdomain(gettext_package, "locale");
	bind_textdomain_codeset(gettext_package, "UTF-8");
	textdomain(gettext_package);

	auto app =
			Gtk::Application::create(argc, argv, PACKAGE_NAME);

	Gtk::Window window;
	window.set_default_size(200, 200);

	return app->run(window);
}
