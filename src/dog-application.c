/* dog-application.c
 *
 * Copyright 2023 sungsphinx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"
#include "dog-application.h"
#include "dog-window.h"
#include "dog-debug-info.h"
#include <glib/gi18n.h>

struct _DogApplication
{
	AdwApplication parent_instance;
};

G_DEFINE_TYPE (DogApplication, dog_application, ADW_TYPE_APPLICATION)

DogApplication *
dog_application_new (const char        *application_id,
                     GApplicationFlags  flags)
{

	return g_object_new (DOG_TYPE_APPLICATION,
	                     "application-id", APPLICATION_ID,
	                     "flags", G_APPLICATION_DEFAULT_FLAGS,
	                     "resource-base-path", "/page/codeberg/SOrg/DogGTK",
	                     NULL);
}


static void
dog_application_activate (GApplication *app)
{
	GtkWindow *window;

	g_assert (DOG_IS_APPLICATION (app));

	window = gtk_application_get_active_window (GTK_APPLICATION (app));

	if (window == NULL)
		window = g_object_new (DOG_TYPE_WINDOW,
		                       "application", app,
		                       NULL);
	gtk_window_present (window);
}

static void
dog_application_class_init (DogApplicationClass *klass)
{
	GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

	gtk_window_set_default_icon_name (APPLICATION_ID);

	app_class->activate = dog_application_activate;
}

static void
dog_application_about_action (GSimpleAction *action,
                              GVariant      *parameter,
                              gpointer       user_data)
{
	static const char *developers[] = {"sungsphinx", NULL};
	static const char *artists[] = {"Google (Noto Color Emoji: Dog, base for App Icon)", "sungsphinx (App Icon)", NULL};
	const char *special_thanks[] = {"Bruno (My Dog)", NULL};
	const char *copyright = "© 2023 Silly Org, 2023 sungsphinx";


	DogApplication *self = user_data;
	char *debug_info;
	void *about;
	GtkWindow *window = NULL;

	debug_info = dog_generate_debug_info ();

	g_assert (DOG_IS_APPLICATION (self));

	window = gtk_application_get_active_window (GTK_APPLICATION (self));

	about = adw_about_window_new_from_appdata ("/page/codeberg/SOrg/DogGTK/metainfo.xml", VERSION_NO_SUFFIX);

	adw_about_window_set_version (ADW_ABOUT_WINDOW (about), VERSION);

	adw_about_window_set_comments (ADW_ABOUT_WINDOW (about), "GTK4 + Libadwaita Game themed around a dog");

	adw_about_window_add_link (ADW_ABOUT_WINDOW (about),
                                    _("_Silly Org Website"),
                              "https://sorg.codeberg.page");

	adw_about_window_add_link (ADW_ABOUT_WINDOW (about),
                                    _("_Application Source Code"),
                              "https://codeberg.org/SOrg/Doggo");

	adw_about_window_add_acknowledgement_section (ADW_ABOUT_WINDOW (about),
                                                _("Special thanks to"),
                                                special_thanks);

	adw_about_window_set_copyright (ADW_ABOUT_WINDOW (about), copyright);

	adw_about_window_set_developers (ADW_ABOUT_WINDOW (about), developers);

	adw_about_window_set_artists (ADW_ABOUT_WINDOW (about), artists);

	adw_about_window_set_debug_info (ADW_ABOUT_WINDOW (about), debug_info);

	adw_about_window_set_debug_info_filename (ADW_ABOUT_WINDOW (about), "doggo-debug.txt");

	gtk_window_set_transient_for (GTK_WINDOW (about), window);

	gtk_window_set_application (GTK_WINDOW (about), GTK_APPLICATION (self));

	gtk_window_present (GTK_WINDOW (about));
}

static void
dog_application_quit_action (GSimpleAction *action,
                             GVariant      *parameter,
                             gpointer       user_data)
{
	DogApplication *self = user_data;

	g_assert (DOG_IS_APPLICATION (self));

	g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
	{ "quit", dog_application_quit_action },
	{ "about", dog_application_about_action },
};

static void
dog_application_init (DogApplication *self)
{
	g_action_map_add_action_entries (G_ACTION_MAP (self),
	                                 app_actions,
	                                 G_N_ELEMENTS (app_actions),
	                                 self);
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "app.quit",
	                                       (const char *[]) { "<primary>q", NULL });
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "win.pet",
	                                       (const char *[]) { "<primary>p", NULL });
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "win.feed",
	                                       (const char *[]) { "<primary>f", NULL });
	gtk_application_set_accels_for_action (GTK_APPLICATION (self),
	                                       "win.abandon",
	                                       (const char *[]) { "<primary>b", NULL });
}
