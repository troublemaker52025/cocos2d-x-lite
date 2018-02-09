/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once

#include <string>
#include "platform/CCPlatformMacros.h"

NS_CC_BEGIN

/**
 * @addtogroup platform
 * @{
 */

class CC_DLL Application
{
public:
    
    /** Since WINDOWS and ANDROID are defined as macros, we could not just use these keywords in enumeration(Platform).
     *  Therefore, 'OS_' prefix is added to avoid conflicts with the definitions of system macros.
     */
    enum class Platform
    {
        WINDOWS,     /**< Windows */
        LINUX,       /**< Linux */
        MAC,         /**< Mac OS X*/
        ANDROID,     /**< Android */
        IPHONE,      /**< iPhone */
        IPAD,        /**< iPad */
    };
    
    enum class LanguageType
    {
        ENGLISH = 0,
        CHINESE,
        FRENCH,
        ITALIAN,
        GERMAN,
        SPANISH,
        DUTCH,
        RUSSIAN,
        KOREAN,
        JAPANESE,
        HUNGARIAN,
        PORTUGUESE,
        ARABIC,
        NORWEGIAN,
        POLISH,
        TURKISH,
        UKRAINIAN,
        ROMANIAN,
        BULGARIAN
    };
    
    Application();
    virtual ~Application();
    
    inline void* getView() const { return _view; }
    
    void start();
    
    /**
     * @brief    Callback by Director for limit FPS.
     * @param interval The time, expressed in seconds, between current frame and next.
     * @js NA
     * @lua NA
     */
    void setAnimationInterval(float interval);
    
    void setMultitouch(bool value);
    
    /**
     @brief Get current language config.
     @return Current language config.
     * @js NA
     * @lua NA
     */
    LanguageType getCurrentLanguage() const;
    
    /**
     @brief Get current language iso 639-1 code.
     @return Current language iso 639-1 code.
     * @js NA
     * @lua NA
     */
    std::string getCurrentLanguageCode() const;
    
    /**
     @brief Get target platform.
     * @js NA
     * @lua NA
     */
    Platform getPlatform() const;
    
    /**
     @brief Open url in default browser.
     @param String with url to open.
     @return True if the resource located by the URL was successfully opened; otherwise false.
     * @js NA
     * @lua NA
     */
    bool openURL(const std::string &url);
    
protected:
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
    virtual void onCreateView(int& x, int& y, int& width, int& height, int& rBits, int& gBits, int& bBits, int& aBits, int& depthBits, int& stencilBits);
    
private:
    void createView();
    
    void* _view = nullptr;
    bool _multiTouch = false;
    void* _delegate = nullptr;
};

// end of platform group
/** @} */

NS_CC_END
