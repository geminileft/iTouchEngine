#import "TouchEngineAppDelegate.h"
#import "EAGLView.h"

#include "FreeCellGame.h"

@implementation TouchEngineAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    mGame = new FreeCellGame(320, 480);
    mGame->initializeIOS();
    return YES;
}

- (void)dealloc
{
    [mWindow release];
    delete mGame;
    [super dealloc];
}

@end
