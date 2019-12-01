#include "systeminfo.h"

SystemInfo::SystemInfo(){
    struct _OSVERSIONINFOW *os_version = new struct _OSVERSIONINFOW;
    os_version->dwOSVersionInfoSize = sizeof(*os_version);
    if (GetVersionExW(os_version)){
        unsigned long platform_id = static_cast<unsigned long>(os_version->dwPlatformId);
        switch (platform_id) {
        case 0:
            platform = "Win32"; break;
        case 1:
            platform = "Windows 95/98"; break;
        case 2:
            platform = "Windows NT"; break;
        case 3:
            platform = "Windows CE"; break;
        case 4:
            platform = "Unix"; break;
        case 5:
            platform = "Xbox"; break;
        case 6:
            platform = "MacOSX"; break;
        }
        major_version = static_cast<unsigned long>(os_version->dwMajorVersion);
        minor_version = static_cast<unsigned long>(os_version->dwMinorVersion);
        build_number =  static_cast<unsigned long>(os_version->dwBuildNumber);
        csd_version = QString::fromWCharArray(os_version->szCSDVersion);
        if (csd_version.length() == 0){
            csd_version = "-";
        }
        osv_error = false;
    }else{
        osv_error = true;
    }
    delete os_version;
    DWORD buffer_size = UNLEN+1;
    wchar_t *buffer = new wchar_t[buffer_size];
    if (GetUserNameW(buffer, &buffer_size)){
        user_name = QString::fromWCharArray(buffer, buffer_size);
    }else{
        user_name = "Не удалось получить имя пользователя";
    }
    delete[] buffer;
    buffer_size = MAX_COMPUTERNAME_LENGTH + 1;
    buffer = new wchar_t[buffer_size];
    if (GetComputerNameW(buffer, &buffer_size)){
        computer_name = QString::fromWCharArray(buffer, buffer_size);
    }else{
        computer_name = "Не удалось получить имя компьютера";
    }
    delete[] buffer;
    buffer_size = MAX_PATH + 1;
    buffer = new wchar_t[buffer_size];
    if (buffer_size = GetSystemDirectoryW(buffer, buffer_size)){
        system_path = QString::fromWCharArray(buffer, buffer_size);
    }else{
        system_path = "Не удалось получить путь к системной папке";
    }
    delete[] buffer;
    buffer_size = MAX_PATH + 1;
    buffer = new wchar_t[buffer_size];
    if (buffer_size = GetWindowsDirectoryW(buffer, buffer_size)){
        windows_path = QString::fromWCharArray(buffer, buffer_size);
    }else{
        windows_path = "Не удалось получить путь к папке windows";
    }
    delete[] buffer;
    buffer_size = MAX_PATH + 1;
    buffer = new wchar_t[buffer_size];
    if (buffer_size = GetTempPathW(buffer_size, buffer)){
        temp_path = QString::fromWCharArray(buffer, buffer_size);
    }else{
        temp_path = "Не удалось получить путь к папке temp";
    }
    delete[] buffer;
}

SystemInfo &SystemInfo::instance(){
    static SystemInfo the_instance;
    return the_instance;
}

const QString SystemInfo::getUserName(){
    return user_name;
}

const QString SystemInfo::getComputerName(){
    return computer_name;
}

const QString SystemInfo::getSystemPath(){
    return system_path;
}

const QString SystemInfo::getWindowsPath(){
    return windows_path;
}

const QString SystemInfo::getTempPath(){
    return temp_path;
}

const QString SystemInfo::getBuild(){
    if (!osv_error){
        return QString::number(build_number);
    }else{
        return "Не удалось получить информацию о версии ОС";
    }
}

const QString SystemInfo::getVersion(){
    if (!osv_error){
        return QString::number(major_version) + "." + QString::number(minor_version);
    }else{
        return "Не удалось получить информацию о версии ОС";
    }
}

const QString SystemInfo::getCSDVersion(){
    if (!osv_error){
        return csd_version;
    }else{
        return "Не удалось получить информацию о версии ОС";
    }
}

const QString SystemInfo::getPlatform(){
    if (!osv_error){
        return platform;
    }else{
        return "Не удалось получить информацию о версии ОС";
    }
}
