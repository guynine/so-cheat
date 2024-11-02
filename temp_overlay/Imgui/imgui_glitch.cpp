#include "imgui_glitch.h"

// Can be edited to accept colors in the form of arguments
void ImGui2::GlitchText(const char* text)
{

    // Red Text
    ImGui::PushStyleColor(ImGuiCol_Text, ImColor(235, 5, 90, 100 + (rand() % 60)).Value);
    ImGui::Text(text);

    // Cyan Text
    ImGui::PushStyleColor(ImGuiCol_Text, ImColor(32, 217, 217, 100 + (rand() % 60)).Value);
    ImGui::Text(text);
    ImGui::PopStyleColor(2);

    // Real Text
    ImGui::Text(text);
}