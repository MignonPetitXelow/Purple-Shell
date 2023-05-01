#include "femfetch.h"

femfetch::femfetch(){}

std::string femfetch::get_cpu(void)
{
    std::string command_output;
    FILE* pipe = popen("cat /proc/cpuinfo | grep 'model name' | uniq | awk '{print $4, $5, $6, $7, $8, $9}'", "r");
    char buffer[128];
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        command_output += buffer;
    }
    pclose(pipe);
    return command_output.c_str();
}

long femfetch::get_totalmemory(void)
{
    struct sysinfo memInfo;
    if(sysinfo(&memInfo) == 0)
    {
        return memInfo.totalram * memInfo.mem_unit;
    }
    else 
    {
        std::cout << "Failed to retrieve memory information" << std::endl;
        return 0;
    }
}

std::string femfetch::get_kernel(void)
{
    struct utsname systemInfo;
    if(uname(&systemInfo) == 0) 
        return systemInfo.release;
    else {
        std::cout << "Failed to retrieve system information" << std::endl;
        return "undefined";
    }
}

std::string femfetch::get_os(void)
{
    struct utsname systemInfo;
    if(uname(&systemInfo) == 0) {
        return systemInfo.sysname;
    }
    else {
        std::cout << "Failed to retrieve system information" << std::endl;
        return "undefined";
    }
}

std::string femfetch::get_distrib(void)
{
    std::ifstream os_release("/etc/os-release");

    if (os_release.is_open()) {
        std::string line;
        while (getline(os_release, line)) {
            if (line.substr(0, 3) == "ID=") {
                return line.substr(3);
                break;
            }
        }
        os_release.close();
    }
    else {
        std::cout << "Failed to open /etc/os-release file." << std::endl;
    }

    return 0;
}

unsigned long femfetch::get_totaldiskspace(void)
{
    struct statvfs diskInfo;
    if (statvfs("/", &diskInfo) == 0) {
        return static_cast<unsigned long long>(diskInfo.f_blocks) * diskInfo.f_frsize;
    }
}

void femfetch::fetch(void)
{
    std::cout << "● 📦 Fetching informations..." << std::endl;
    std::cout << PURPLE_FOREGROUND <<
    "                     ,.    .      .//*                      \n" <<
    "                         ,      , ,.     ./(/,              " << "   __                __      _       _     " << std::endl <<
    "(@/      &                    /,.,.***,,,,,,,,,,.,#,,,/.    " << "  / _|              / _|    | |     | |    " << std::endl <<
    "/%\##% /\%%#                 * ,,,,*/(,,,*,,,,,,,,..,,,,(,.*/" << "   | |_ ___ _ __ ___ | |_ ___| |_ ___| |__  " << std::endl <<
    "                         , ...,,,,,.,,,,,,,,*,,....,,,,*    " << "  |  _/ _ \\ '_ ` _ \\|  _/ _ \\ __/ __| '_ \\" << std::endl <<
    "           %/# #**%.    (.......,,,,........,,*........***, " << "  | ||  __/ | | | | | ||  __/ || (__| | | |" << std::endl <<
    "                   *. ....,,....,,,...,,,,,,,,,*,*.........," << "  |_| \\___|_| |_| |_|_| \\___|\\__\\___|_| |_" << std::endl <<
    "    #/#&/#,          (,.,,.,.,/,*,,*,*****,**/****,,,,.,*,/*\n" << 
    "                     .**,.,,./**//*/*//,/////*********/*/(*.\n" <<
    "                      / /#*(((,, ((///,.*,,.*///**/**/////*/\n" <<
    "   %*  #(.  ( *& &    /*#(*(#(*,./,...*....,./****/******   " << " ○ Kernel: " << get_kernel() << std::endl <<
    "   #//&.& *( ,.%,*      ..#//(.    ..      ..///**///***( . " << " ○ Os:     " << get_os() << "-" << get_distrib() << std::endl <<
    "           (#//*/(        , ,//,            *****/(...,#*.  " << " ○ Cpu:    " << get_cpu()<<
    " /#,(                     .,,(,*(*.      .**,(*%,.        / " << " ○ Ram:    " << get_totalmemory()/1000000 << "Mb" << std::endl <<
    "&                           (  ..**/*&%/%\%%\%%&%#..         (" << " ○ Disk    " << get_totaldiskspace()/1000000000 << "Gb" << std::endl <<
    "                            *    ,,,,\%%\%%\%\%%\%%\%(.          .\n" <<
    "                             ,    ..,##%\######%\%.        . .\n" <<
    "          &%.      (          ,  ...*###(########.       ,..\n" <<
    "          &&.&,( &*(           *  ..(############,       ,.%\n" <<
    "                      . .* ..   #*(###############      .%\%%\n" <<
    "                ,(*      /      *##%\%%\%\%#########%##(##%&%\%%\n" <<
    "%/%             *(&%#.#%#(       ##%\%%\%%\%%\%\%%\%%\%%\%%\%#%\%%&%\%%\n" <<
    "                                 .%\%%\%&%\%%\%\%%\%%\%\%\%%\%%\%%\%%\#%\%\n";
}

