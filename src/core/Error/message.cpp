#include "message.h"
/*                                                                                               */
Message::Message(QString iconName,QString file,int line,QString content)
{
    m_iconName=iconName;
    m_file=file;
    m_line=line;

    if(!file.isEmpty() && content.startsWith(file)){
        content=content.mid(file.size());
        m_content=content.mid(content.indexOf(" ")+1);
    }
    else
        m_content=content;
}
/*                                                                                               */
QVector<Message*> Message::messages;