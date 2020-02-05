PHP_ARG_WITH(sfml, whether to enable sfml bindings,
[  --with-sfml[=Path]         Enable the sfml extension])

if test "$PHP_SFML" != "no"; then
  # --with-sfml -> check with-path
  SEARCH_PATH="/usr/local /usr"
  REQUIRED_HEADERS="Audio.hpp Graphics.hpp Network.hpp System.hpp Window.hpp"
  REQUIRED_LIBS="sfml-audio sfml-graphics sfml-network sfml-system sfml-window"

  for path in $PHP_SFML $SEARCH_PATH ; do
    if test -z "$SFML_INCLUDE_DIR"; then
      FOUND_HEADERS="yes"
      for h in $REQUIRED_HEADERS ; do
        if ! test -r $path/include/SFML/$h; then
          FOUND_HEADERS="no"
          break;
        fi
      done

      if test "$FOUND_HEADERS" != "no"; then
        SFML_INCLUDE_DIR=$path/include
        AC_MSG_RESULT([found required SFML header files at $SFML_INCLUDE_DIR])
      fi
    fi

    if test -z "$SFML_LIB_DIR"; then
      FOUND_LIBS="yes"
      for l in $REQUIRED_LIBS ; do
        if test -r $path/$PHP_LIBDIR/lib$l.a || test -r $path/$PHP_LIBDIR/lib$l.$SHLIB_SUFFIX_NAME; then
          LIB_DIR=$path/$PHP_LIBDIR
        elif test -r $path/lib$l.a || test -r $path/lib$l.$SHLIB_SUFFIX_NAME; then
          LIB_DIR=$p
        else
          FOUND_LIBS="no"
        fi
      done

      if test "$FOUND_LIBS" != "no"; then
        SFML_LIB_DIR=$LIB_DIR
        AC_MSG_RESULT([found required SFML libraries at $SFML_LIB_DIR])
      fi
    fi

    if ! test -z "$SFML_INCLUDE_DIR" && ! test -z "$SFML_LIB_DIR"; then
      break;
    fi
  done

  if test -z "$SFML_INCLUDE_DIR" || test -z "$SFML_LIB_DIR"; then
    AC_MSG_RESULT([sfml not found])
    AC_MSG_ERROR([Please reinstall the sfml distribution])
  fi

  PHP_REQUIRE_CXX()

  dnl apparently PHP_REQUIRE_CXX() isn't good enough if we're compiling as a shared library
  PHP_ADD_LIBRARY(stdc++, 1, SFML_SHARED_LIBADD)

  PHP_ADD_INCLUDE($SFML_INCLUDE_DIR)
  for l in $REQUIRED_LIBS ; do
    PHP_ADD_LIBRARY_WITH_PATH($l, $SFML_LIB_DIR, SFML_SHARED_LIBADD)
  done

  PHP_SUBST(SFML_SHARED_LIBADD)

  SFML_SOURCE_FILES="`find src -name "*.cpp"`"
  PHP_NEW_EXTENSION(sfml, php_sfml.cpp $SFML_SOURCE_FILES, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -std=c++11)
  PHP_ADD_BUILD_DIR($ext_builddir/src, 1)
  PHP_ADD_INCLUDE($ext_builddir)
fi