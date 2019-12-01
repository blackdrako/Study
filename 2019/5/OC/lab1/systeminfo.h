#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QString>

#include <windows.h>
#include <lmcons.h>
#include <winbase.h>
#include <tchar.h>

class SystemInfo
{
private:
    unsigned long major_version;
    unsigned long minor_version;
    unsigned long build_number;
    QString platform;
    QString csd_version;
    QString user_name;
    QString computer_name;
    QString system_path;
    QString windows_path;
    QString temp_path;
    bool osv_error;
    SystemInfo();
    SystemInfo(const SystemInfo&) = delete;
    SystemInfo& operator=(const SystemInfo&) = delete;
public:
    static SystemInfo& instance();
    const QString getUserName();
    const QString getComputerName();
    const QString getSystemPath();
    const QString getWindowsPath();
    const QString getTempPath();
    const QString getBuild();
    const QString getVersion();
    const QString getCSDVersion();
    const QString getPlatform();
};

#endif // SYSTEMINFO_H
