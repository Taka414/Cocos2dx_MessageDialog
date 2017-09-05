#pragma once

#include "cocos2d.h"
#include "ui\UIScale9Sprite.h"

// ダメージ表示を表します。
class MessageDialog : public cocos2d::Node
{
    //
    // Fields
    // - - - - - - - - - - - - - - - - - - - -

    // 画面に表示する部品
    cocos2d::ui::Scale9Sprite* frame = nullptr;
    cocos2d::Label* label = nullptr;

    std::function<void()> completedAction = nullptr;

    // 表示する文字列を記憶しておくリスト
    std::vector<std::string> messageList;
    // 現在表示中の文字
    std::string message;
    // 現在のメッセージ位置
    size_t messageIndex = 0;

    // 末尾に表示される矢印
    cocos2d::Sprite* finishArrow;

    // 現在の文字位置
    int charIndex = 0;
    // 現在の文字列の長さ
    int messageLength = 0;
    // 文字送り中はtrue
    bool isSending = false;
    // 文字と文字を表示する間隔
    float interval = 0.04f;
    // 前の文字を表示してからの経過時間
    float distance = 0;

    //
    // Methods
    // - - - - - - - - - - - - - - - - - - - -

    // ラベルを準備する
    void prepareLabel();

    // 文字送りアニメーションの定義
    void update(float delta);

    // 矢印のアニメーション
    void startArrowBlink();
    void stopAllowBlink();

public:
    
    // いつもの
    MessageDialog() { /* nop */ }

    // いつもの
    ~MessageDialog();

    // いつもの
    virtual bool init(const int frameWidth, const int frameHeight);
    
    // いつもの
    static MessageDialog* create(const int frameWidth, const int frameHeight);

    // 表示する文字を追加する
    void addMessage(const std::string &message);

    // 文字送りを開始する
    void start();

    // 次の動作(残りを全部一括で表示、次のパラグラフ)
    void next();

    // ダイアログの内容が全部読みお終わったときに呼ばれるコールバックの設定
    void setCompleteAction(std::function<void()> completedAction);

    // サイズの変更
    void setContentSize(const cocos2d::Size& contentSize) override;
};