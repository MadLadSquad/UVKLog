#pragma once
#include "UVKLog.h"
#ifdef UVK_LOG_IMGUI
#if __has_include(<imgui.h>)
#include "imgui.h"

namespace UVKLog
{
    class UVK_PUBLIC_API ImGuiConsole
    {
    public:
        void displayFull(bool& bOpen, bool* bInteractingWithTextbox) noexcept;
        void display(bool* bInteractingWithTextbox) noexcept;

        static void addToMessageLog(const std::string& msg, LogType type) noexcept;
        static void addCommand(const CommandType& cmd) noexcept;

        void setLogColour(ImVec4 colour, LogType type) noexcept;
    private:
        friend class LoggerInternal;

        static void showHelpMessage(const std::string&) noexcept;

        ImVec4 success = { 0.0f, 1.0f, 0.0f, 1.0f };
        ImVec4 warning = { 1.0f, 1.0f, 0.0f, 1.0f };
        ImVec4 error = { 1.0f, 0.0f, 0.0f, 1.0f };
        ImVec4 note = { 0.0f, 0.0f, 1.0f, 1.0f };
        ImVec4 message = { 1.0f, 1.0f, 1.0f, 1.0f };
    };
}
#else
#error Dear ImGui is not in the include path!. Consider adding it so that "#include <imgui.h>" is a valid line
#endif
#endif
