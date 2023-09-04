using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;

namespace PongFrameWork.Collisions
{
    public class ProgressBarP:IWallCollide
    {
        public EventHandler onDecrementScore;
        public void decrementProgressBar(int value)
        {
            onDecrementScore?.Invoke(value,EventArgs.Empty);
        }
    }
}
