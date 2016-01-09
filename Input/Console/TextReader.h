#ifndef CTEXTREADER_H
#define CTEXTREADER_H

#include <QObject>

class cTextReader : public QObject
{
  Q_OBJECT
public:
  explicit cTextReader(QObject *parent = 0);

  // perform readings from console
  void DoWork();

signals:

public slots:
};

#endif // CTEXTREADER_H
