/* application.c
 *
 * Copyright 2024 sungsphinx, 2023-2024 Silly Org
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
#include "application.h"
#include "window.h"
#include "debug-info.h"
#include <glib/gi18n.h>
#include <adwaita.h>

struct _DoggoApplication
{
  AdwApplication parent_instance;
  AdwPreferencesDialog *preferences;
};

G_DEFINE_TYPE (DoggoApplication, doggo_application, ADW_TYPE_APPLICATION)

DoggoApplication *
doggo_application_new (const char        *application_id,
                     GApplicationFlags  flags)
{

  return g_object_new (DOGGO_TYPE_APPLICATION,
                       "application-id", APPLICATION_ID,
                       "flags", G_APPLICATION_DEFAULT_FLAGS,
                       "resource-base-path", "/app/drey/Doggo",
                       NULL);
}


static void
doggo_application_activate (GApplication *app)
{
  GtkWindow *window;

  g_assert (DOGGO_IS_APPLICATION (app));

  window = gtk_application_get_active_window (GTK_APPLICATION (app));

  if (window == NULL)
    window = g_object_new (DOGGO_TYPE_WINDOW,
                           "application", app,
                           NULL);
  gtk_window_present (window);
}

static void
doggo_application_class_init (DoggoApplicationClass *klass)
{
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  gtk_window_set_default_icon_name (APPLICATION_ID);

  app_class->activate = doggo_application_activate;
}

static void
doggo_application_about_action (GSimpleAction *action,
                              GVariant      *state,
                              gpointer       user_data)
{
  static const char *developers[] = {"Dexter Reed https://sungsphinx.codeberg.page", NULL};
  static const char *artists[] = {"Dexter Reed https://sungsphinx.codeberg.page", NULL};
  const char *special_thanks[] = {"Bruno (A Real Doggo) https://codeberg.org/SOrg/Doggo/raw/branch/main/data/ui/images/bjrunoada.jpg", NULL};
  const char *copyright = "© 2023 Silly Org, 2023 Dexter Reed (sungsphinx)";


  DoggoApplication *self = user_data;
  char *debug_info;
  GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION(self));
  AdwDialog *dialog;

  debug_info = doggo_generate_debug_info ();

  g_assert (DOGGO_IS_APPLICATION (self));

  window = gtk_application_get_active_window (GTK_APPLICATION (self));

  dialog = adw_about_dialog_new_from_appdata ("/app/drey/Doggo/metainfo.xml", VERSION_NO_SUFFIX);

  adw_about_dialog_set_version (ADW_ABOUT_DIALOG (dialog), VERSION);

  adw_about_dialog_set_comments (ADW_ABOUT_DIALOG (dialog), "Clicker &amp; chance game");

  adw_about_dialog_add_link (ADW_ABOUT_DIALOG (dialog),
                                    _("_Silly Org Website"),
                              "https://sorg.codeberg.page");

  adw_about_dialog_add_link (ADW_ABOUT_DIALOG (dialog),
                                    _("_Application Source Code"),
                              "https://codeberg.org/SOrg/Doggo");

  adw_about_dialog_add_acknowledgement_section (ADW_ABOUT_DIALOG (dialog),
                                                _("Special thanks to"),
                                                special_thanks);

  adw_about_dialog_set_copyright (ADW_ABOUT_DIALOG (dialog), copyright);

  adw_about_dialog_set_developers (ADW_ABOUT_DIALOG (dialog), developers);

  adw_about_dialog_set_artists (ADW_ABOUT_DIALOG (dialog), artists);

  adw_about_dialog_set_debug_info (ADW_ABOUT_DIALOG (dialog), debug_info);

  adw_about_dialog_set_debug_info_filename (ADW_ABOUT_DIALOG (dialog), "doggo-debug.txt");

  adw_dialog_present (dialog, GTK_WIDGET (window));
}

static void
doggo_application_quit_action (GSimpleAction *action,
                             GVariant      *parameter,
                             gpointer       user_data)
{
  DoggoApplication *self = user_data;

  g_assert (DOGGO_IS_APPLICATION (self));

  g_application_quit (G_APPLICATION (self));
}

static void
open_link (const char *uri,
           gpointer       user_data)
{
  DoggoApplication *self = user_data;
  GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION(self));
  GCancellable *cancellable;
  GAsyncReadyCallback callback;
  GtkUriLauncher *urilauncher;
  cancellable = g_cancellable_new ();
  callback = NULL;
  urilauncher = gtk_uri_launcher_new (uri);
  gtk_uri_launcher_launch (urilauncher, window, cancellable, callback, user_data);
}

static void
open_issue_link (void)
{
  open_link ("https://codeberg.org/SOrg/Doggo/issues/new/choose", NULL);
}

static void
doggo_application_unavailable_action (GSimpleAction *action,
                             GVariant      *parameter,
                             gpointer       user_data)
{
  DoggoApplication *self = user_data;
  GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION(self));
  AdwDialog *dialog;

  dialog = adw_alert_dialog_new (_("Unavailable"), NULL);

  adw_alert_dialog_format_body (ADW_ALERT_DIALOG (dialog),
                              _("The location you were trying to access was unavailable.\n\nPossible Reasons:\n\n1. Location Is Under Development / W.I.P\n2. Something Wrong in the code\n3. Location has been removed or disabled"));

  adw_alert_dialog_add_responses (ADW_ALERT_DIALOG (dialog),
                                  "close",  _("Close"),
                                  "report", _("_Report"),
                                  NULL);

  adw_alert_dialog_set_default_response (ADW_ALERT_DIALOG (dialog), "close");
  adw_alert_dialog_set_close_response (ADW_ALERT_DIALOG (dialog), "close");

  g_signal_connect (dialog, "response::report", G_CALLBACK (open_issue_link), self);

  adw_dialog_present (dialog, GTK_WIDGET(window));
}

static const GActionEntry app_actions[] = {
  { "quit", doggo_application_quit_action },
  { "about", doggo_application_about_action },
  { "unavailable_dialog", doggo_application_unavailable_action },
};

static void
doggo_application_init (DoggoApplication *self)
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

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.clickershow",
                                         (const char *[]) { "<primary>c", NULL });

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.kbd-shortcuts",
                                         (const char *[]) { "<primary><shift><super>g", NULL });

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.help",
                                         (const char *[]) { "<primary><shift>F1", NULL });
}

