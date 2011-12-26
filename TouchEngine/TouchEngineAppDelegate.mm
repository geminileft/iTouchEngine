#import "TouchEngineAppDelegate.h"
#import "EAGLView.h"

@implementation TouchEngineAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    CGRect frame = [[UIScreen mainScreen] bounds];
    EAGLView* view = [[EAGLView alloc] initWithFrame:frame];
    mWindow = [[UIWindow alloc] initWithFrame:frame];
    UIViewController* vc = [[UIViewController alloc] init];
    vc.view = view;
    mWindow.rootViewController = vc;
    
    mGame = new FreeCellGame(frame.size.width, frame.size.height);
    mGame->initializeIOS(view.layer);
    [mWindow makeKeyAndVisible];
    return YES;
}

- (void)dealloc
{
    [mWindow release];
    delete mGame;
    [super dealloc];
}

@end
