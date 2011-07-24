/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Elizabeth M Smith <auroraeosrose@php.net>                    |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_GIR_EXT_H
#define PHP_GIR_EXT_H

#define PHP_GIR_VERSION "0.1.0-dev"
#define GIR_NAMESPACE "Gir"

extern zend_module_entry gir_module_entry;
#define phpext_gir_ptr &gir_module_entry

#ifdef PHP_WIN32
# define PHP_GIR_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_GIR_API __attribute__ ((visibility("default")))
#else
# define PHP_GIR
#endif

#ifdef ZTS
# include "TSRM.h"
#endif

/* Globals */
ZEND_BEGIN_MODULE_GLOBALS(gir)
	int module_number;
ZEND_END_MODULE_GLOBALS(gir)

#ifdef ZTS
# define GIRG(v) TSRMG(gir_globals_id, zend_gir_globals *, v)
#else
# define GIRG(v) (gir_globals.v)
#endif

ZEND_EXTERN_MODULE_GLOBALS(gir)

#include <girepository.h>
#include <girffi.h>

#endif	/* PHP_GIR_EXT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
