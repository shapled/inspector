#include <sstream>

#include "mysql/plugin.h"
#include "rpl_filter.h"
#include "sql_string.h"

extern Rpl_filter *rpl_filter;
extern Rpl_filter *binlog_filter;

struct st_mysql_daemon inspector_decriptor = { MYSQL_DAEMON_INTERFACE_VERSION };

static int 
inspector_rpl_filter_do_db(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    std::stringstream ss;
    I_List<i_string> *do_dbs = rf->get_do_db();
    I_List_iterator<i_string> iter(*do_dbs);
    i_string *item;
    while (NULL != (item = iter++)) {
      if (ss.tellp()) {
        ss << " | ";
      }
      ss << item->ptr;
    }
    strncpy(buff, ss.str().c_str(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_rpl_filter_ignore_db(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    std::stringstream ss;
    I_List<i_string> *ignore_dbs = rf->get_ignore_db();
    I_List_iterator<i_string> iter(*ignore_dbs);
    i_string *item;
    while (NULL != (item = iter++)) {
      if (ss.tellp()) { ss << " | "; }
      ss << item->ptr;
    }
    strncpy(buff, ss.str().c_str(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_rpl_filter_do_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    String str;
    rf->get_do_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_rpl_filter_ignore_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    String str;
    rf->get_ignore_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_rpl_filter_wild_do_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    String str;
    rf->get_wild_do_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_rpl_filter_wild_ignore_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = rpl_filter;

  if (rf) {
    String str;
    rf->get_wild_ignore_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_do_db(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    std::stringstream ss;
    I_List<i_string> *do_dbs = rf->get_do_db();
    I_List_iterator<i_string> iter(*do_dbs);
    i_string *item;
    while (NULL != (item = iter++)) {
      if (ss.tellp()) {
        ss << " | ";
      }
      ss << item->ptr;
    }
    strncpy(buff, ss.str().c_str(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_ignore_db(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    std::stringstream ss;
    I_List<i_string> *ignore_dbs = rf->get_ignore_db();
    I_List_iterator<i_string> iter(*ignore_dbs);
    i_string *item;
    while (NULL != (item = iter++)) {
      if (ss.tellp()) {
        ss << " | ";
      }
      ss << item->ptr;
    }
    strncpy(buff, ss.str().c_str(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_do_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    String str;
    rf->get_do_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_ignore_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    String str;
    rf->get_ignore_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_wild_do_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    String str;
    rf->get_wild_do_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static int 
inspector_binlog_filter_wild_ignore_table(MYSQL_THD thd, SHOW_VAR *var, char *buff) {
  (void)thd;
  var->type = SHOW_CHAR;
  var->value = NULL;
  Rpl_filter *rf = binlog_filter;

  if (rf) {
    String str;
    rf->get_wild_ignore_table(&str);
    strncpy(buff, str.c_ptr_safe(), SHOW_VAR_FUNC_BUFF_SIZE);
    buff[SHOW_VAR_FUNC_BUFF_SIZE - 1] = 0;
    var->value = buff;
  }
  return 0;
}

static SHOW_VAR inspector_status_variables[] = {
  {"inspector_rpl_filter_do_db", (char *)inspector_rpl_filter_do_db,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_rpl_filter_ignore_db", (char *)inspector_rpl_filter_ignore_db,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_rpl_filter_do_table", (char *)inspector_rpl_filter_do_table,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_rpl_filter_ignore_table",
   (char *)inspector_rpl_filter_ignore_table, SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_rpl_filter_wild_do_table",
   (char *)inspector_rpl_filter_wild_do_table, SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_rpl_filter_wild_ignore_table",
   (char *)inspector_rpl_filter_wild_ignore_table, SHOW_FUNC,
   SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_do_db", (char *)inspector_binlog_filter_do_db,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_ignore_db", (char *)inspector_binlog_filter_ignore_db,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_do_table", (char *)inspector_binlog_filter_do_table,
   SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_ignore_table",
   (char *)inspector_binlog_filter_ignore_table, SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_wild_do_table",
   (char *)inspector_binlog_filter_wild_do_table, SHOW_FUNC, SHOW_SCOPE_GLOBAL},
  {"inspector_binlog_filter_wild_ignore_table",
   (char *)inspector_binlog_filter_wild_ignore_table, SHOW_FUNC,
   SHOW_SCOPE_GLOBAL},
  {NULL, NULL, SHOW_LONG, SHOW_SCOPE_GLOBAL}
};

mysql_declare_plugin(inspector) 
{
  MYSQL_DAEMON_PLUGIN,
  &inspector_decriptor,
  "inspector",
  "Shapled",
  "Inspector Plugin",
  PLUGIN_LICENSE_GPL,
  NULL,
  NULL,
  0x0101,
  inspector_status_variables,
  NULL,
  NULL,
  0,
} 
mysql_declare_plugin_end;
