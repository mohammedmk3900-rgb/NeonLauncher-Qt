#include "TranslationManager.h"

TranslationManager::TranslationManager(QObject *parent) : QObject(parent) {
    loadTranslations();
}

void TranslationManager::setCurrentLanguage(const QString &lang) {
    if (m_currentLanguage != lang && (lang == "en" || lang == "fa")) {
        m_currentLanguage = lang;
        emit languageChanged();
    }
}

void TranslationManager::loadTranslations() {
    // ترجمه‌های انگلیسی
    m_translationsEn["app_title"] = "Neon Launcher";
    m_translationsEn["games_scanned"] = "Games Scanned";
    m_translationsEn["auto_save"] = "Real-Time Auto-Save";
    m_translationsEn["settings"] = "Settings";

    // ترجمه‌های فارسی
    m_translationsFa["app_title"] = "لانچر نئونی";
    m_translationsFa["games_scanned"] = "بازی‌های اسکن‌شده";
    m_translationsFa["auto_save"] = "ذخیره خودکار لحظه‌ای";
    m_translationsFa["settings"] = "تنظیمات";
}

QString TranslationManager::getText(const QString &key) {
    if (m_currentLanguage == "fa") {
        if (m_translationsFa.contains(key))
            return m_translationsFa[key].toString();
    } else {
        if (m_translationsEn.contains(key))
            return m_translationsEn[key].toString();
    }
    return key; // اگر کلید پیدا نشد، خود کلید برگردانده شود
}
