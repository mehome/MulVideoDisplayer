#ifndef FFMPEGCPUDECODE_H
#define FFMPEGCPUDECODE_H

#include "decodetaskmanagerimpl.h"
class FFmpegCpuDecode : public DecodeTask
{
public:
    FFmpegCpuDecode(DecodeTaskManagerImpl *taskManger, QObject *parent = nullptr);
    ~FFmpegCpuDecode() override;
    void startPlay(QString) override;
    void stop() override;
    int fps() override;
    int curFps() override;

protected:
    void run() override;

private:
    int decode_packet(AVCodecContext *avctx, AVPacket *packet, AVFrame *frame);

    DecodeTaskManagerImpl *taskManager_ = nullptr;
    QString url_;
    bool isDecodeStarted_ = false;
    uint8_t *buffer_ = nullptr;
    int bufferSize_ = 0, fps_ = 0, curFps_ = 0;
    qint64 start_pt_ = 0, last_pts_ = AV_NOPTS_VALUE;
    int decode_frames_ = 0;
    AVRational stream_time_base_;
};

#endif // FFMPEGCPUDECODE_H
