import { Microphone } from './App-styling';
import IconButton from '@mui/material/IconButton';
import MicIcon from '@mui/icons-material/Mic';
import MicOffIcon from '@mui/icons-material/MicOff';
import SpeechRecognition, { useSpeechRecognition } from 'react-speech-recognition';

const App = () =>  {
  
  const {
    transcript,
    listening,
    resetTranscript,
    browserSupportsSpeechRecognition
  } = useSpeechRecognition();
  let error = (!browserSupportsSpeechRecognition) ? <h3>Browser no apto para la webapp.</h3> : null;
  const Icon = listening ? MicIcon : MicOffIcon;
  return (
    <Microphone>
      <IconButton 
        className="mic"
        onMouseDown={SpeechRecognition.startListening}
        onMouseUp={SpeechRecognition.stopListening} 
      >
        <Icon className="icon"/>
      </IconButton>
      <div className='transcription'>
        {transcript}
      </div>
      {error}
    </Microphone>
  );
}

export default App;
