/* dog-window.c
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

#include "window.h"

struct _DogWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
	AdwHeaderBar        *header_bar;
	//GtkLabel            *wooflabel;
	GtkLabel            *title_result;
	GtkLabel            *smalltxt;
	AdwNavigationView   *navigationview1;
};

G_DEFINE_FINAL_TYPE (DogWindow, dog_window, ADW_TYPE_APPLICATION_WINDOW)

static void
dog_window_class_init (DogWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/page/codeberg/SOrg/DogGTK/window.ui");
	gtk_widget_class_bind_template_child (widget_class, DogWindow, header_bar);
	gtk_widget_class_bind_template_child (widget_class, DogWindow, navigationview1);
}

enum Choices {
  PET,
  FEED
};

enum Results_Pet {
  FRIENDLY,
  UNFRIENDLY,
  BITE
};

enum Results_Feed {
  ENJOY_FOOD,
  DISLIKE_FOOD
};

static void
display_result_pet (DogWindow *self) {
	int result_choice = g_random_int_range (0, BITE + 1);

	if (result_choice == UNFRIENDLY) {
          adw_navigation_view_pop (self->navigationview1);
          adw_navigation_view_push_by_tag (self->navigationview1, "dog_unfriendly_page");
	}

	if (result_choice == FRIENDLY) {
          adw_navigation_view_pop (self->navigationview1);
          adw_navigation_view_push_by_tag (self->navigationview1, "dog_friendly_page");
	}

	if (result_choice == BITE) {
          adw_navigation_view_pop (self->navigationview1);
          adw_navigation_view_push_by_tag (self->navigationview1, "dog_bite_page");
	}
}

static void
display_result_feed (DogWindow *self) {
	int result_choice = g_random_int_range (0, DISLIKE_FOOD + 1);

	if (result_choice == ENJOY_FOOD) {
          adw_navigation_view_pop (self->navigationview1);
          adw_navigation_view_push_by_tag (self->navigationview1, "dog_food_page");
        }

        if (result_choice == DISLIKE_FOOD) {
          adw_navigation_view_pop (self->navigationview1);
          adw_navigation_view_push_by_tag (self->navigationview1, "dog_dislikefood_page");
        }
}

static void
register_gaction (DogWindow *self, const char *action_name, GCallback handler) {
	GSimpleAction *action = g_simple_action_new (action_name, NULL);
	g_signal_connect_swapped (action, "activate", handler, self);
	g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (action));
}

static void
pet (DogWindow *self) {
	display_result_pet (self);
}

static void
feed (DogWindow *self) {
	display_result_feed (self);
}

static void
abandon (DogWindow *self) {
	g_print ("Abandon Dog ");
	adw_navigation_view_pop (self->navigationview1);
	adw_navigation_view_push_by_tag (self->navigationview1, "dog_abandon_page");
}

static void
dog_window_init (DogWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
	if (g_strcmp0 (PROFILE, ".Devel") == 0)
	gtk_widget_add_css_class (GTK_WIDGET (self), "devel");
	register_gaction (self, "pet", G_CALLBACK(pet));
	register_gaction (self, "feed", G_CALLBACK(feed));
	register_gaction (self, "abandon", G_CALLBACK(abandon));
}
