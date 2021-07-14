AC_INIT([Chat],
        [3.11.1],
        [https://gitlab.gnome.org/GNOME/gnome-chat/-/issues/],
        [gnome-chat],
        [https://wiki.gnome.org/Design/Apps/Chat])
AC_PREREQ(2.63)

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE([dist-xz no-dist-gzip tar-ustar])
AM_MAINTAINER_MODE([enable])

AC_PROG_CC
AC_PROG_CC_C_O
AC_HEADER_STDC

GLIB_GSETTINGS

GLIB_MIN_VERSION=2.35.1
GTK_MIN_VERSION=3.13.1

TP_GLIB_MIN_VERSION=0.19.9
AC_DEFINE(TP_SEAL_ENABLE, 1, [Prevent to use sealed variables])
AC_DEFINE(TP_VERSION_MAX_ALLOWED, TP_VERSION_0_20, [Prevent post 0.20 APIs])
AC_DEFINE(TP_VERSION_MIN_REQUIRED, TP_VERSION_0_20, [Ignore post 0.20 deprecations])

TP_LOGGER_MIN_VERSION=0.8.0

GNOME_COMMON_INIT
GNOME_COMPILE_WARNINGS([maximum])
GNOME_DEBUG_CHECK
GNOME_MAINTAINER_MODE_DEFINES

IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=AC_PACKAGE_TARNAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$GETTEXT_PACKAGE"],
                   [GETTEXT package name])
AM_GLIB_GNU_GETTEXT

LT_INIT

PKG_CHECK_MODULES(GLIB, [glib-2.0 >= $GLIB_MIN_VERSION])
PKG_CHECK_MODULES(GIO, [gio-2.0])
PKG_CHECK_MODULES(GTK, [gtk+-3.0 >= $GTK_MIN_VERSION])
PKG_CHECK_MODULES(TP_GLIB, [telepathy-glib >= $TP_GLIB_MIN_VERSION])
PKG_CHECK_MODULES(TP_LOGGER, [telepathy-logger-0.2 >= $TP_LOGGER_MIN_VERSION])

GLIB_COMPILE_RESOURCES=`$PKG_CONFIG --variable glib_compile_resources gio-2.0`
AC_SUBST(GLIB_COMPILE_RESOURCES)

# telepathy-account-widgets

prev_top_build_prefix=$ac_top_build_prefix
prev_ac_configure_args=$ac_configure_args
ac_configure_args="$ac_configure_args --with-cheese=no --disable-gudev"
ac_configure_args="$ac_configure_args --with-pkgdatadir=${datadir}/gnome-chat"
ac_configure_args="$ac_configure_args --with-icondir=${datadir}/icons"
ac_configure_args="$ac_configure_args --with-gettext-package=gnome-chat-tpaw"
ac_configure_args="$ac_configure_args --disable-schemas-compile --disable-settings"
AX_CONFIG_DIR([telepathy-account-widgets])
ac_top_build_prefix=$prev_top_build_prefix
ac_configure_args=$prev_ac_configure_args

export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:"$ac_top_build_prefix"telepathy-account-widgets/
PKG_CHECK_MODULES(TPAW, telepathy-account-widgets)

AC_CONFIG_FILES([
Makefile
data/Makefile
data/gnome-chat.desktop.in
src/Makefile
po/Makefile.in
])
AC_OUTPUT
