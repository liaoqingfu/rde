#include "errorservice.h"
/*                                                                                               */
void MessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch(type){
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        Message::messages.append(new Message("dialog-information",context.file,context.line,localMsg.constData()));
        //fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        Message::messages.append(new Message("dialog-warning",context.file,context.line,localMsg.constData()));
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        Message::messages.append(new Message("dialog-error",context.file,context.line,localMsg.constData()));
        //fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        Message::messages.append(new Message("dialog-error",context.file,context.line,localMsg.constData()));
        //fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}
/* Constructor                                                                                   */
ErrorService::ErrorService():Service("Error")
{
    qInstallMessageHandler(MessageHandler);
    qmlRegisterType<MessageModel>("org.rde.message",1,0,"MessageModel");
    qmlRegisterType<FileReader>("org.rde.message",1,0,"FileReader");
}
/* static                                                                                        */
ErrorService* ErrorService::m_instance;
ErrorService *ErrorService::instance(){if(!m_instance)m_instance=new ErrorService;return m_instance;}