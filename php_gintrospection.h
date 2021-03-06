/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
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

#ifndef PHP_GINTROSPECTION_EXT_H
#define PHP_GINTROSPECTION_EXT_H

#include "php_gintrospection_public.h"

#include <ext/standard/info.h>
#include <zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

#include <girepository.h>
#include <girffi.h>

/* typelib info */
struct _gintrospection_typelib_object {
	zend_object std;
	zend_bool   is_constructed;
	GITypelib  *typelib;
};

/* baseinfo object */
struct _gintrospection_baseinfo_object {
	zend_object std;
	zend_bool   is_constructed;
	GIBaseInfo *info;
};

#define PHP_GINTROSPECTION_EXCEPTIONS \
	zend_error_handling error_handling; \
	zend_replace_error_handling(EH_THROW, spl_ce_InvalidArgumentException, &error_handling TSRMLS_CC);

#define PHP_GINTROSPECTION_RESTORE_ERRORS \
	zend_restore_error_handling(&error_handling TSRMLS_CC);

#define REGISTER_ENUM_CONST(const_name, value, ce) \
	zend_declare_class_constant_long(ce, const_name, sizeof(const_name)-1, (long)value TSRMLS_CC);

extern zend_class_entry* php_gintrospection_get_info_ce(GIBaseInfo *info);

extern zend_module_entry gintrospection_module_entry;
#define phpext_gintrospection_ptr &gintrospection_module_entry

#endif /* PHP_GINTROSPECTION_EXT_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
