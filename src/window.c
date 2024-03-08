/* window.c
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

#include "window.h"

struct _DoggoWindow
{
  AdwApplicationWindow  parent_instance;

  /* Template widgets */
  AdwHeaderBar        *header_bar;
  //GtkLabel      *wooflabel;
  GtkLabel      *title_result;
  GtkLabel      *clickslabel;
  AdwNavigationView   *navigationview1;
};

G_DEFINE_FINAL_TYPE (DoggoWindow, doggo_window, ADW_TYPE_APPLICATION_WINDOW)

static void
doggo_window_class_init (DoggoWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/app/drey/Doggo/window.ui");
  gtk_widget_class_bind_template_child (widget_class, DoggoWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, DoggoWindow, navigationview1);
  gtk_widget_class_bind_template_child (widget_class, DoggoWindow, clickslabel);
}

enum Choices {
  PET,
  FEED
};

enum Results_Pet {
  FRIENDLY,
  UNFRIENDLY,
  AFFECTIONATE,
  NEUTRAL,
  SLEEPING,
  BITE,
  DEAD
};

enum Results_Feed {
  ENJOY_FOOD,
  DISLIKE_FOOD,
  DEAD_FOOD
};

int clickamount;
char clickamountchars[1000000];
bool fakeunavdialogopen = false;
bool fakeunavdialogopenable = true;
bool fakeunavdialogdoeasteregg = false;
bool fakeunavdialogeastereggfound = false;

static void
open_link (const char *uri,
     DoggoWindow *self)
{
  GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION(self));
  GCancellable *cancellable;
  GAsyncReadyCallback callback;
  GtkUriLauncher *urilauncher;
  cancellable = g_cancellable_new ();
  callback = NULL;
  urilauncher = gtk_uri_launcher_new (uri);
  gtk_uri_launcher_launch (urilauncher, window, cancellable, callback, self);
}

static void
open_issue_link (void)
{
  open_link ("https://codeberg.org/SOrg/Doggo/issues/new/choose", NULL);
}

static void
unavailable_dialog (DoggoWindow *self)
{
  AdwDialog *dialog;

  dialog = adw_alert_dialog_new ("Unavailable", NULL);

  adw_alert_dialog_format_body (ADW_ALERT_DIALOG (dialog),
            "The location you were trying to access was unavailable.\n\nPossible Reasons:\n\n1. Location Is Under Development / W.I.P\n2. Something Wrong in the code\n3. Location has been removed or disabled");

  adw_alert_dialog_add_responses (ADW_ALERT_DIALOG (dialog),
                "close",  "Close",
                "report", "_Report",
                NULL);

  adw_alert_dialog_set_default_response (ADW_ALERT_DIALOG (dialog), "close");
  adw_alert_dialog_set_close_response (ADW_ALERT_DIALOG (dialog), "close");

  g_signal_connect (dialog, "response::report", G_CALLBACK (open_issue_link), self);
  adw_dialog_present (dialog, GTK_WIDGET(self));
}

static void
fake_unavailable_dialog_on_closed (DoggoWindow *self)
{
  fakeunavdialogopen = false;
  if (fakeunavdialogeastereggfound == true) {
    fakeunavdialogdoeasteregg = false;
  } else if (fakeunavdialogeastereggfound == false) {
    fakeunavdialogdoeasteregg = true;
  }
}

static void
fake_unavailable_dialog (DoggoWindow *self)
{
  if (fakeunavdialogopen == true) {
    fakeunavdialogopenable = false;
  } else if (fakeunavdialogopen == false && fakeunavdialogopenable == true) {
    AdwDialog *dialog;

    dialog = adw_alert_dialog_new ("Unavailable", NULL);

    adw_alert_dialog_format_body (ADW_ALERT_DIALOG (dialog),
            "The location you were trying to access was unavailable.\n\nPossible Reasons:\n\n1. Location Is Under Development / W.I.P\n2. Something Wrong in the code\n3. Location has been removed or disabled");

    adw_alert_dialog_add_responses (ADW_ALERT_DIALOG (dialog),
                "close",  "Close",
                "report", "_Report",
                NULL);

    adw_alert_dialog_set_default_response (ADW_ALERT_DIALOG (dialog), "close");
    adw_alert_dialog_set_close_response (ADW_ALERT_DIALOG (dialog), "close");

    g_signal_connect (dialog, "response::report", G_CALLBACK (open_issue_link), self);
    g_signal_connect (dialog, "response", G_CALLBACK (fake_unavailable_dialog_on_closed), self);
    adw_dialog_present (dialog, GTK_WIDGET (self));
    //g_print ("%d\n", fakeunavdialogopen);
    // You can only open it once ;)
    // Yes it's intended, this is an easter egg..
    //fakeunavdialogopen = false;
    fakeunavdialogopenable = false;
  }
}

static void
display_result_pet (DoggoWindow *self) {
  int result_choice = g_random_int_range (0, DEAD + 1);

  if (result_choice == UNFRIENDLY) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "unfriendly_page");
  }

  if (result_choice == FRIENDLY) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "friendly_page");
  }

  if (result_choice == AFFECTIONATE) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "affectionate_page");
  }

  if (result_choice == NEUTRAL) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "neutral_page");
  }

  if (result_choice == SLEEPING) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "sleeping_page");
  }

  if (result_choice == BITE) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "bite_page");
  }

  if (result_choice == DEAD) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "dead_page");
  }
}

static void
display_result_feed (DoggoWindow *self) {
  int result_choice = g_random_int_range (0, DEAD_FOOD + 1);

  if (result_choice == ENJOY_FOOD) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "food_page");
  }

  if (result_choice == DISLIKE_FOOD) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "dislikefood_page");
  }

  if (result_choice == DEAD_FOOD) {
    adw_navigation_view_pop (self->navigationview1);
    adw_navigation_view_push_by_tag (self->navigationview1, "deadfood_page");
  }
}

static void
register_gaction (DoggoWindow *self, const char *action_name, GCallback handler) {
  GSimpleAction *action = g_simple_action_new (action_name, NULL);
  g_signal_connect_swapped (action, "activate", handler, self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (action));
}

static void
pet (DoggoWindow *self) {
  display_result_pet (self);
}

static void
feed (DoggoWindow *self) {
  display_result_feed (self);
}

static void
abandon (DoggoWindow *self) {
  adw_navigation_view_pop (self->navigationview1);
  adw_navigation_view_push_by_tag (self->navigationview1, "abandon_page");
}

static void
clicker_show (DoggoWindow *self) {
  adw_navigation_view_pop (self->navigationview1);
  adw_navigation_view_push_by_tag (self->navigationview1, "clicker_page");
}

static void
clickamount_increment (DoggoWindow *self, int amount) {
  clickamount = clickamount + amount;
  sprintf(clickamountchars, "%d Clicks", clickamount);
  //g_print ("Click Amount Incremented: %s\n", clickamountchars);
  gtk_label_set_label (self->clickslabel, clickamountchars);
}

static void
click (DoggoWindow *self) {
  clickamount_increment (self, 1);
}

static void
secret1 (DoggoWindow *self) {
    if (fakeunavdialogdoeasteregg == true) {
      AdwDialog *dialog;

      dialog = adw_alert_dialog_new ("Doggo", NULL);

      adw_alert_dialog_format_body (ADW_ALERT_DIALOG (dialog),
              "Congratulations, you have found an easter egg, now take 999999999 Clicks!");

      adw_alert_dialog_add_responses (ADW_ALERT_DIALOG (dialog),
                  "close",  "Close",
                  NULL);

      adw_alert_dialog_set_default_response (ADW_ALERT_DIALOG (dialog), "close");
      adw_alert_dialog_set_close_response (ADW_ALERT_DIALOG (dialog), "close");

      adw_dialog_present (dialog, GTK_WIDGET (self));

      adw_navigation_view_pop (self->navigationview1);
      adw_navigation_view_push_by_tag (self->navigationview1, "clicker_page");

      clickamount_increment (self, 999999999);

      fakeunavdialogeastereggfound = true;
      fakeunavdialogdoeasteregg = false;

    } else if (fakeunavdialogdoeasteregg == false) {
      //g_print ("don't do easter egg");
    }
}

static void
doggo_window_init (DoggoWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  if (g_strcmp0 (PROFILE, ".Devel") == 0)
  gtk_widget_add_css_class (GTK_WIDGET (self), "devel");
  register_gaction (self, "pet", G_CALLBACK(pet));
  register_gaction (self, "feed", G_CALLBACK(feed));
  register_gaction (self, "abandon", G_CALLBACK(abandon));
  register_gaction (self, "help", G_CALLBACK(fake_unavailable_dialog));
  register_gaction (self, "inspector", G_CALLBACK(secret1));
  register_gaction (self, "clicker", G_CALLBACK(clicker_show));
  register_gaction (self, "click", G_CALLBACK(click));
}
