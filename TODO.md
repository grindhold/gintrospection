TODO
===

 1. repository.c - g_irepository_load_typelib - can't really do this until I can create typelibs
 1. repository.c - g_irepository_get_option_group - can't do this until the glib/gobject deps are done
 1. repository.c - g_irepository_find_by_gtype  - need gtype stuff from glib

 1. typelib.c - g_typelib_new_from_memory - need glib
 1. typelib.c - g_typelib_new_from_const_memory - need glib
 1. typelib.c - g_typelib_new_from_mapped_file - need glib and gio?
 1. typelib.c - g_typelib_symbol - need glib

 1. info.c - (registeredtypeinfo) g_registered_type_info_get_g_type - need gobject for gtype return

TEST
===
 1. enuminfo get(Num)Method(s) tests are bogus at the moment, they need an enum with methods to test on
 1. baseinfo getattribute and getattributes also have bogus tests since nothing has attributes yet
 1. Someday a custom typelib with all items would be great to for testing!
 1. discriminator stuff can't be propertly tested with no discriminator to test

IGNORED
===
 1. G_IREPOSITORY_ERROR (g_irepository_error_quark()) - managed by GError stuff
 1. g_typelib_free - managed by object destruction
 1. GIAttributeIter - attributes exposed as PHP array, no need for this
 1. g_base_info_ref - handled in repository methods that retrieve infos
 1. g_base_info_unref - handled in object destruction

NOTES
===
possibly add an "importNamespace" to do class_alias help

baseinfo might be good to get some built in mangling? we might wait for import to do that
getName - getCName(as is) getMangledName(to camelcase) getFullName(full namespaced path?)