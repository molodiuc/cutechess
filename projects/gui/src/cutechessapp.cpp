/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QCoreApplication>
#include <QTime>
#include <QSettings>

#include "cutechessapp.h"

CuteChessApplication::CuteChessApplication(int& argc, char* argv[])
	: QApplication(argc, argv)
{
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

	QCoreApplication::setOrganizationName("cutechess");
	QCoreApplication::setOrganizationDomain("cutechess.org");
	QCoreApplication::setApplicationName("cutechess");

	// Use Ini format on all platforms
	QSettings::setDefaultFormat(QSettings::IniFormat);
}

CuteChessApplication::~CuteChessApplication()
{
}
