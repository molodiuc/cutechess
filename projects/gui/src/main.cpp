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

#include <QDebug>
#include <QTextStream>
#include "cutechessapp.h"
#include "mainwindow.h"

int main(int argc, char* argv[])
{
	CuteChessApplication app(argc, argv);

	QStringList arguments = app.arguments();
	arguments.takeFirst(); // application name

	// Use trivial command-line parsing for now
	QTextStream out(stdout);
	while (!arguments.isEmpty())
	{
		if (arguments.first() == QLatin1String("-v") ||
			arguments.first() == QLatin1String("--version"))
		{
			out << "Cute Chess " << CUTECHESS_VERSION << endl;
			out << "Using Qt version " << qVersion() << endl << endl;
			out << "Copyright (C) 2008-2009 Ilari Pihlajisto and Arto Jonsson" << endl;
			out << "This is free software; see the source for copying ";
			out << "conditions.  There is NO" << endl << "warranty; not even for ";
			out << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.";
			out << endl << endl;

			return 0;
		}
		else
		{
			qWarning() << "Unknown argument:" << arguments.first();
		}
		arguments.takeFirst();
	}

	MainWindow mainWindow;
	mainWindow.show();

	return app.exec();
}

