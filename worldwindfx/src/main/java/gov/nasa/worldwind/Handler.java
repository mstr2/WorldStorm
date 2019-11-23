package gov.nasa.worldwind;

public class Handler {

    public interface Callback {
        boolean handleMessage(Message message);
    }

    private final MessageQueue messageQueue;
    private final Callback callback;

    public Handler() {
        this.messageQueue = MessageQueue.getInstance();
        this.callback = null;
    }

    public Handler(Handler.Callback callback) {
        this.messageQueue = MessageQueue.getInstance();
        this.callback = callback;
        messageQueue.registerHandler(this);
    }

    void handleMessage(Message message) {
        if (callback != null) {
            callback.handleMessage(message);
        }
    }

    public boolean hasMessages(int what) {
        return messageQueue.hasMessages(what);
    }

    public void removeMessages(int what) {
        messageQueue.removeMessages(what);
    }

    public boolean sendMessage(Message message) {
        return messageQueue.sendMessage(message);
    }

    public boolean post(Runnable runnable) {
        return messageQueue.post(runnable);
    }

    public boolean sendEmptyMessage(int what) {
        return sendMessage(new Message(what, null));
    }

    public boolean sendEmptyMessageDelayed(int what, long delayMillis) {
        throw new UnsupportedOperationException();
    }

}
