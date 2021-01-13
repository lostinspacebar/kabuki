/**
 * KABUKI GAME ENGINE
 * ----------------------------------------------------------------------------
 * @file    path_utils.hpp
 * @brief   Utility methods for file paths.
 */

#include <string>

#ifndef KABUKI_PATH_UTILS_H
#define KABUKI_PATH_UTILS_H

namespace kabuki::utility::path
{
    static bool has_extension(const std::string &file_path, const std::string &extension)
    {
        return file_path.compare(file_path.size() - extension.size(), extension.size(), extension) == 0;
    }
}

#endif