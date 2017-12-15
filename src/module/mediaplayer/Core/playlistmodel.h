#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H
/*                                                                                               */
#include "Model.h"
#include "player.h"
#include <QFileInfo>
/*                                                                                               */
class PlaylistModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

public:
    explicit PlaylistModel();
    ~PlaylistModel();
    int currentIndex(){return Player::instance()->playlist()->currentIndex();}
    void setCurrentIndex(int index){if(Player::instance()->playlist()->currentIndex()!=index)Player::instance()->playlist()->setCurrentIndex(index);}
private:
    enum Roles{Title,Artist};
    QHash<int,QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{return Player::instance()->playlist()->mediaCount();}

private slots:
    void mediaAboutToBeInserted(const int &start,const int &end);
    void mediaInserted(const int &start,const int &end);
    void mediaAboutToBeRemoved(const int &start,const int &end);
    void mediaRemoved(const int &start,const int &end);
    void indexChanged(const int &index);
    void loaded();
    void loadFailed();

signals:
    void currentIndexChanged();
};
/*                                                                                               */
#endif