#ifndef DICTINFO_H
#define DICTINFO_H

#include "QFile"
#include "QString"

#define GET_METHOD_TEMPL(type, field) \
    type get_##field(void) const \
    { \
        return field; \
    }

#define SET_METHOD_TEMPL(type, field) \
    void set_##field(type field) \
    { \
        this->field = field; \
        this->f_##field = true; \
    }

#define UNSET_METHOD_TEMPL(type, field, default_val) \
    void unset_##field(void) \
    { \
        this->f_##field = false; \
        this->field = default_val; \
    }

#define IS_METHOD_TEMPL(type, field) \
    bool is_##field(void) const \
    { \
        return f_##field; \
    }

#define ALL_METHOD_TEMPL(type, field, default_val) \
    GET_METHOD_TEMPL(type, field) \
    SET_METHOD_TEMPL(type, field) \
    UNSET_METHOD_TEMPL(type, field, default_val) \
    IS_METHOD_TEMPL(type, field)

enum DictInfoType {
    DictInfoType_NormDict,
    DictInfoType_TreeDict,
    DictInfoType_ResDb
};

class DictInfo
{
public:
    DictInfo();
    bool load_from_file(QString &, DictInfoType &);
    void clear(void);

    QString ifofilename;

    ALL_METHOD_TEMPL(qint32, wordcount, 0)
    ALL_METHOD_TEMPL(qint32, filecount, 0)
    ALL_METHOD_TEMPL(qint32, synwordcount, 0)
    ALL_METHOD_TEMPL(QString&, bookname, "")
    ALL_METHOD_TEMPL(QString&, author, "")
    ALL_METHOD_TEMPL(QString&, email, "")
    ALL_METHOD_TEMPL(QString&, website, "")
    ALL_METHOD_TEMPL(QString&, date, "")
    ALL_METHOD_TEMPL(QString&, description, "")
    ALL_METHOD_TEMPL(qint32, index_file_size, 0)
    ALL_METHOD_TEMPL(QString&, sametypesequence, "")
    ALL_METHOD_TEMPL(QString&, dicttype, "")
    ALL_METHOD_TEMPL(QString&, version, "")
    ALL_METHOD_TEMPL(DictInfoType, infotype, DictInfoType_NormDict)
signals:
        warning_message(QString &);
        error_message(QString &);

private:
        qint32 wordcount;
        qint32 filecount;
        qint32 synwordcount;
        QString bookname;
        QString author;
        QString email;
        QString website;
        QString date;
        QString description;
        qint32 index_file_size;
        QString sametypesequence;
        QString dicttype;
        QString version;
        DictInfoType infotype;

};

#endif // DICTINFO_H
