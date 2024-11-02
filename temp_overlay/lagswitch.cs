#pragma once

using System;
using System.Runtime.InteropServices;

System.Diagnostics;

void InternetConnection(std::string str)
{
    ProcessStartInfo internet = new ProcessStartInfo()
    {
        FileName = "cmd.exe",
        Arguments = "/C ipconfig /" + str,
        WindowStyle = ProcessWindowStyle.Hidden
    };
    Process.Start(internet);
}