class H2O {

    private int hCount = 0;
    private int oCount = 0;

    public H2O() {}

    public synchronized void hydrogen(Runnable releaseHydrogen)
            throws InterruptedException {

        // If already 2 H present, wait
        while (hCount == 2) {
            wait();
        }

        // Release hydrogen
        releaseHydrogen.run();
        hCount++;

        // If molecule complete → reset
        if (hCount == 2 && oCount == 1) {
            hCount = 0;
            oCount = 0;
            notifyAll();
        }
    }

    public synchronized void oxygen(Runnable releaseOxygen)
            throws InterruptedException {

        // If already 1 O present, wait
        while (oCount == 1) {
            wait();
        }

        // Release oxygen
        releaseOxygen.run();
        oCount++;

        // If molecule complete → reset
        if (hCount == 2 && oCount == 1) {
            hCount = 0;
            oCount = 0;
            notifyAll();
        }
    }
}
