/*
 * Chat - instant messaging client for GNOME
 * Copyright © 2013 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */


#ifndef CHAT_MANAGER_H
#define CHAT_MANAGER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define CHAT_TYPE_MANAGER (chat_manager_get_type ())

#define CHAT_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   CHAT_TYPE_MANAGER, ChatManager))

#define CHAT_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   CHAT_TYPE_MANAGER, ChatManagerClass))

#define CHAT_IS_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   CHAT_TYPE_MANAGER))

#define CHAT_IS_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   CHAT_TYPE_MANAGER))

#define CHAT_MANAGER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   CHAT_TYPE_MANAGER, ChatManagerClass))

typedef struct _ChatManager        ChatManager;
typedef struct _ChatManagerClass   ChatManagerClass;
typedef struct _ChatManagerPrivate ChatManagerPrivate;

struct _ChatManager
{
  GObject parent_instance;
  ChatManagerPrivate *priv;
};

struct _ChatManagerClass
{
  GObjectClass parent_class;
};

GType                      chat_manager_get_type               (void) G_GNUC_CONST;

ChatManager               *chat_manager_dup_singleton          (void);

G_END_DECLS

#endif /* CHAT_MANAGER_H */
