核心思想
外观模式提供了一个高级别的接口，将多个底层接口组合成一个更简单的接口，以供客户端使用。这有助于隔离客户端代码和复杂子系统之间的耦合关系。
主要组成部分
1）外观类（Facade）：提供一个简单的接口，封装了对一个或多个子系统的复杂操作。它知道如何与子系统协调工作以完成特定任务。
2）子系统类（Subsystems）：这些类包含了系统的具体实现，但对客户端是不可见的。客户端通过外观类来与这些子系统进行交互。
特点
1）简化接口：外观模式提供了一个简化的接口，隐藏了子系统的复杂性，使客户端更容易使用。
2）降低耦合：客户端代码与子系统之间的依赖性降低，因为客户端只需与外观对象交互，而不需要直接与多个子系统交互。
3）改进可维护性：外观模式将系统的组件组织得更好，有助于维护和修改系统的不同部分，而不会影响客户端。
示例
开发一个多媒体播放器应用程序，其中包含音频播放、视频播放和字幕显示等多个子系统。
你可以使用外观模式来创建一个多媒体播放器的外观类，将这些子系统组合起来，并提供一个简化的接口供客户端使用：

#include <iostream>
#include <string>
using namespace std;

//外观类-多媒体播放器
class Multimediaplayer{
private:
  AudioPlayer audioPlayer;
  VideoPlayer videoPlayer;
  SubtitlePlayer subtitlePlayer;

public:
  MultimediaPlayer() {
    //初始化子系统
  }
  
  //提供一个播放多媒体文件的简化接口
  void playMedia(const string& mediaFilePath)
  {
    audioPlayer.playAudio(mediaFilePath);
    videoPlayer.playerVideo(mediaFilePath);
    subtitlePlayer.displaySubtitles(mediaFilePath);
  }
};

//子系统类—音频播放器
class AudioPlayer{
public:
  void playAudio(const string& filePath)
  {
    cout<<"播放音频"<<filePath<<endl;
    //实际的音频播放逻辑
  }
};

//子系统类-视频播放器
class VideoPalyer{
public:
  void playVideo(const string& filePath)
  {
    cout<<"播放视频"<<filPath<<endl;
    //实际视频播放逻辑
  }
};

//子系统类-字幕显示器
class SubtitlePlayer{
public:
  void displaySubtitles(const string& filePath)
  {
    cout<<"字幕显示"<<filePath<<endl;
  //实际的字幕显示逻辑
  }
};

int main()
{
  MultimediaPlayer player;
  player.playMedia("example.mp4");
  return 0;
}

