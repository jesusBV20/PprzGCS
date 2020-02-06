#ifndef TILEITEM_H
#define TILEITEM_H

#include <QGraphicsPixmapItem>
#include "point2dtile.h"

class TileItem : public QGraphicsPixmapItem
{

public:
    TileItem(TileItem* mother, QGraphicsItem *parent = nullptr);
    TileItem(const QPixmap &pixmap, Point2DTile coordinates, TileItem* mother, QGraphicsItem *parent = nullptr);
    TileItem(Point2DTile coordinates, TileItem* mother, QGraphicsItem *parent = nullptr);

    bool isInScene() { return inScene;}
    bool hasData() {return _hasData;}
    void setInScene(bool in_s) {inScene = in_s;}
    Point2DTile coordinates() {return _coordinates;}
    TileItem* child(int x, int y) {return _childs[x][y];}
    void setChild(TileItem* t, int x, int y) {_childs[x][y] = t;}
    TileItem* mother() {return _mother;}

    virtual void setPixmap(const QPixmap &pixmap);

private:
    bool inScene;
    bool _hasData;
    Point2DTile _coordinates;
    TileItem* _childs[2][2];
    TileItem* _mother;
};

class TileIterator {
public:
    TileIterator(TileItem* base, int maxDepth = 19);
    TileItem* next();

private:
    TileItem* current;
    QVector<int> explore;
    int maxDepth;
};

#endif // TILEITEM_H
