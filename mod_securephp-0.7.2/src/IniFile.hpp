/*
    suPHP - (c)2002-2008 Sebastian Marsching <sebastian@marsching.com>

    This file is part of suPHP.

    suPHP is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    suPHP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with suPHP; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef SUPHP_INIFILE_H

namespace suPHP {
    class IniFile;
};

#define SUPHP_INIFILE_H

#include <string>
#include <vector>
#include <map>

#include "KeyNotFoundException.hpp"
#include "ParsingException.hpp"
#include "IOException.hpp"
#include "IniSection.hpp"

namespace suPHP {
    /**
     * Class providing access to configuration in a INI file.
     */
    class IniFile {
    private:
        std::map<std::string, IniSection> sections;
        
        std::string parseValue(const std::string& value) const throw (ParsingException);

    public:
        /**
         * Reads values from INI file
         */
        void parse(const File& file) throw (IOException, ParsingException);

        /**
         * Returns section
         */
        const IniSection& getSection(const std::string& name) const throw (KeyNotFoundException);
        
        /**
         * Index operator
         */
        const IniSection& operator[](const std::string& name) const throw (KeyNotFoundException);

        /**
         * Returns vector containing names of all sections
         */
        const std::vector<const std::string> getSections();

        /**
         * Checks wheter a section is existing
         */
        bool hasSection(const std::string& name) const;
    };
};

#endif // SUPHP_INIFILE_H
