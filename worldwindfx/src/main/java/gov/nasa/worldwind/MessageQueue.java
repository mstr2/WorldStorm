package gov.nasa.worldwind;

import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class MessageQueue {

    private static final MessageQueue instance = new MessageQueue();

    private final Queue<Object> items = new LinkedList<>();
    private final List<WeakReference<Handler>> handlers = new ArrayList<>();
    private final Runnable scheduleRun = this::runOnce;
    private boolean scheduled;

    static MessageQueue getInstance() {
         return instance;
    }

    private void schedule() {
        if (!scheduled) {
            scheduled = true;
            javafx.application.Platform.runLater(scheduleRun);
        }
    }

    private synchronized void runOnce() {
        scheduled = false;

        while (!items.isEmpty()) {
            Object item = items.poll();

            if (item instanceof Message) {
                Message message = (Message)item;

                Iterator<WeakReference<Handler>> it = handlers.iterator();
                while (it.hasNext()) {
                    Handler handler = it.next().get();
                    if (handler != null) {
                        handler.handleMessage(message);
                    } else {
                        it.remove();
                    }
                }
            } else if (item instanceof Runnable) {
                ((Runnable)item).run();
            }
        }
    }

    synchronized void registerHandler(Handler handler) {
        handlers.add(new WeakReference<>(handler));
    }

    synchronized boolean hasMessages(int what) {
        for (Object item : items) {
            if (item instanceof Message && ((Message)item).what == what) {
                return true;
            }
        }

        return false;
    }

    synchronized void removeMessages(int what) {
        items.removeIf(item -> item instanceof Message && ((Message)item).what == what);
    }

    synchronized boolean sendMessage(Message message) {
        items.add(message);
        schedule();
        return true;
    }

    synchronized boolean post(Runnable runnable) {
        items.add(runnable);
        schedule();
        return true;
    }

}
