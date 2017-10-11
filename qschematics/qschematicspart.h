#ifndef QSCHEMATICSPART_H
#define QSCHEMATICSPART_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

#include "symbol_reader/schematicssymbol.h"

class QSchematicsPart : public QGraphicsItem
{
public:
	QSchematicsPart(symbol::SchematicsSymbol*obj, QString name, int x, int y);

	QPainterPath shape() const;
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private:
	QRectF m_externalRect;
};

#endif // QSCHEMATICSPART_H