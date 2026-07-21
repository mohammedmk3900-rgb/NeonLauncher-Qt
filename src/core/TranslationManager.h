#pragma once

#include <QObject>
#include <QString>
#include <QVariantMap>

class TranslationManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY languageChanged)

public:
    explicit TranslationManager(QObject *parent = nullptr);

    QString currentLanguage() const { return m_currentLanguage; }
    Q_INVOKABLE void setCurrentLanguage(const QString &lang);

    // تابع اصلی برای دریافت متن ترجمه‌شده بر اساس کلید
    Q_INVOKABLE QString getText(const QString &key);

signals:
    void languageChanged();

private:
    QString m_currentLanguage = "en"; // زبان پیش‌فرض: انگلیسی
    QVariantMap m_translationsEn;
    QVariantMap m_translationsFa;
    void loadTranslations();
};
