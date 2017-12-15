#include "filereader.h"
/*                                                                                               */
FileReader::FileReader()
{
}
/*                                                                                               */
void FileReader::setFile(QString file)
{
    if(!file.isEmpty()){
        file=file.mid(7);
        m_file=file;
        QFile f(file);
        if(f.open(QIODevice::ReadOnly)){

            m_content=QString(f.readAll());
            emit contentChanged();
        }
    }
}
/*                                                                                               */