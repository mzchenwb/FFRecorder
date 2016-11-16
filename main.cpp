#include <iostream>
#include "FFAudioMixing.hpp"
#include "FFAudioBufferEncoder.hpp"

int main2() {
    int err = 0;
    {
        FFAudioBufferEncoder encoder("/Users/chenweibin/out.m4a", ".m4a", 128000);
        err = encoder.beginInput();
        if (err != 0)
            goto ERROR;

        FILE *file = fopen("/Users/chenweibin/reverseme.pcm", "r");
        std::vector<uint8_t> buffer;
        buffer.resize(4 * 1024);

        size_t readed = 0;
        do {
            readed = fread(&buffer.front(), 1, buffer.size(), file);
            printf("readed %d\n", (int) readed);
            err = encoder.appendData(&buffer.front(), readed);
            if (err != 0)
                goto ERROR;
        } while (readed == buffer.size());

        fclose(file);

        encoder.endInput();
    }

    ERROR:
    return 0;
}