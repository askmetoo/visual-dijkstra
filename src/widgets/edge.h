/*          Visual Dijkstra
 *    Copyright (C) 2021 Samuele Girgenti
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * 	     --  CONTACTS --
 *   Email:      samuele.girgenti458@gmail.com
 *   Github:     https://github.com/Samuele458
 */

#ifndef EDGE_H
#define EDGE_H
#include <QGraphicsItem>
#include <QStyle>
#include <QGraphicsSceneMouseEvent>
#include <QInputDialog>
#include <QRegularExpression>
#include <QMessageBox>

#include "widgets/node.h"
#include "common/error.h"

class EdgeError : public Error {
public:
    enum id {
        GENERIC,
        INVALID_ARGUMENT,

        INVALID_NODES,
        INVALID_WEIGHT
    };

    EdgeError( id error_id = GENERIC, QString message = "" ) :
        Error( (Error::id)error_id, message ) { }
};

class Node;

class Edge : public QGraphicsItem
{
public:
    //allow the use of qgraphicsitem_cast
    enum { Type = UserType + 2 };
    int type() const override { return Type; }

    Edge( Node* nodeA, Node* nodeB, int weight, QGraphicsItem* parent = nullptr );
    ~Edge() {
        prepareGeometryChange();
    }

    bool operator==( Edge& other );
    bool operator!=( Edge& other );

    Node* getNodeA() const;
    Node* getNodeB() const;
    int getWeight() const;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void setColor( QColor color );
    QColor getColor() const;

    QString toString() const;
protected:
    QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    int weight;
    Node* nodeA;
    Node* nodeB;

    //Edge color
    QColor color;

};

#endif // EDGE_H
