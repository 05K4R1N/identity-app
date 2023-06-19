import { Microphone } from './App-styling';
import IconButton from '@mui/material/IconButton';
import MicIcon from '@mui/icons-material/Mic';
import MicOffIcon from '@mui/icons-material/MicOff';
import SpeechRecognition, { useSpeechRecognition } from 'react-speech-recognition';
import { useState } from 'react';

const App = () =>  {
  
  const [message, setMessage] = useState();
  const commands = [
    {
      command: "tell me a good place to work",
      callback: () => {
        setMessage("Acid Labs");
      },
    },
    {
      command: [
        "i consider * a good place to live",
        "* has many kind of cultures",
        "the people of * are friendly"
      ],
      callback: (place) => {
        setMessage(`Seems like ${place} is awesome!`)
      },
    },
  ];

  const {
    transcript,
    listening,
    resetTranscript,
    browserSupportsSpeechRecognition
  } = useSpeechRecognition({ commands });
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
      <div className='response'>
        {message}
      </div>
      {error}
    </Microphone>
  );
}

export default App;
