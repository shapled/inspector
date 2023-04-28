## Install

Copy the `inspector` directory in the project to the `plugin` directory of mysql, then recompile and install mysql, and you will get an inspector.so.

```sql
install plugin inspector soname "inspector.so";
```

## Usage

```sql
mysql> show status like 'ins%';
+-------------------------------------------+--------+
| Variable_name                             | Value  |
+-------------------------------------------+--------+
| inspector_binlog_filter_do_db             |        |
| inspector_binlog_filter_do_table          |        |
| inspector_binlog_filter_ignore_db         |        |
| inspector_binlog_filter_ignore_table      |        |
| inspector_binlog_filter_wild_do_table     |        |
| inspector_binlog_filter_wild_ignore_table |        |
| inspector_rpl_filter_do_db                |        |
| inspector_rpl_filter_do_table             |        |
| inspector_rpl_filter_ignore_db            |        |
| inspector_rpl_filter_ignore_table         |        |
| inspector_rpl_filter_wild_do_table        | test.% |
| inspector_rpl_filter_wild_ignore_table    |        |
+-------------------------------------------+--------+
```

## Uninstall

```sql
uninstall plugin inspector;
```

## Supported Versions

This plugin was developed under mysql 5.7 with plans to support 5.6 and 8.0.

## Note

This plug-in may **NOT** be thread-safe. If you access and modify the filter at the same time, it may cause thread safety problems, depending on whether mysql's Rpl_filter itself supports multi-threaded access.

Any issue or pull request is welcome.

Please star thie repo if it's useful, Thanks!
