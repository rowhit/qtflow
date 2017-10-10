#include "schematicsdata.h"
#include "schematicsscanner.h"

namespace schematics {
	SchematicsData::SchematicsData(QString filename) :
		lexer(NULL),
		parser(NULL),
		trace_scanning(false),
		trace_parsing(false),
		paperHeigth(0),
		paperWidth(0),
		recentComponent(SchematicsPart())
	{
		std::ifstream input;
		std::string stdfilename = filename.toStdString();

		streamname = filename;
		input.open(stdfilename, std::ios::in);

		lexer = new SchematicsScanner(&input, &std::cout);
		lexer->set_debug(trace_scanning);

		parser = new SchematicsParser(this);
		//parser->set_debug_level(trace_parsing);
		parser->parse();
		input.close();
	}

	SchematicsScanner *SchematicsData::getLexer()
	{
		return lexer;
	}

	void SchematicsData::addWire(std::string name, int x1, int y1, int x2, int y2)
	{
		SchematicsWire wire = SchematicsWire(QString::fromStdString(name),x1,y1,x2,y2);
		wires.append(wire);
	}

	void SchematicsData::setFormat(std::string format, int w, int h)
	{
		paperName = QString::fromStdString(format);
		paperWidth = w;
		paperHeigth = h;
	}

	QVector<SchematicsWire> SchematicsData::getWires()
	{
		return wires;
	}

	QVector<SchematicsPart> SchematicsData::getParts()
	{
		return parts;
	}

	void SchematicsData::setRecentPartName(std::string name)
	{
		recentComponent.setName(QString::fromStdString(name));
	}

	void SchematicsData::setRecentPartType(std::string name)
	{
		recentComponent.setType(QString::fromStdString(name));
	}

	void SchematicsData::setRecentPartPosition(int x, int y)
	{
		recentComponent.setPosition(x,y);
	}

	void SchematicsData::storeRecentComponent()
	{
		parts.append(recentComponent);
		recentComponent = SchematicsPart();
	}

	qreal SchematicsData::getPaperWidth()
	{
		return paperWidth;
	}

	qreal SchematicsData::getPaperHeigth()
	{
		return paperHeigth;
	}
}
