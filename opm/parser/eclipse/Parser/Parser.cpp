/*
  Copyright 2013 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <opm/parser/eclipse/Parser/Parser.hpp>
#include <opm/parser/eclipse/Parser/ParserKW.hpp>
#include <opm/parser/eclipse/RawDeck/RawParserKWs.hpp>
#include <opm/parser/eclipse/Logger/Logger.hpp>
#include <opm/parser/eclipse/Deck/Deck.hpp>


namespace Opm {

    Parser::Parser() {
    }

    DeckPtr Parser::parse(const std::string &path) {
        Logger::initLogger();
        Logger::info("Starting parsing of file: " + path);

        RawDeckPtr rawDeck(new RawDeck(RawParserKWsConstPtr(new RawParserKWs())));
        rawDeck->parse(path);

        for (size_t i = rawDeck->getNumberOfKeywords(); i++) {
            RawKeywordPtr rawKeyword = rawDeck->getKeyword(0);
        }
        
        
        Logger::info("Done parsing of file: " + path);
        Logger::closeLogger();
        return deck;
    }
  



    Parser::~Parser() {
    }

    void Parser::addKW(ParserKWConstPtr parserKW) {
        m_parserKeywords.insert(std::make_pair(parserKW->getName(), parserKW));
    }

} // namespace Opm
