-- Copyright 2008 fulinux <fulinux@sina.com>
-- Licensed to the public under the Apache License 2.0.

module("luci.controller.admin.new_tab", package.seeall) --notice that new_tab is the name of the file new_tab.lua
function index()                                                                                                                    
        entry({"admin", "new_tab"}, firstchild(), "苏联大学网络助手", 30).dependent=false  --this adds the top level tab and defaults to the first sub-tab (tab_from_cbi), also it is set to position 30                                                  
        entry({"admin", "new_tab", "tab_from_view"}, template("admin_myapp/view_tab"), _("设置"), 2)  --this adds the second sub-tab that is located in /usr/lib/lua/luci/view/admin_myapp and the file is called view_tab.htm, also set to the second position
end
